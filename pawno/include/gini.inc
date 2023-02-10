/*
	INI File manager Include (gini.inc)
	* One of my oldest include! Now fast ini processing! Handling like DINI but faster.
	* This is just a fresh version! Added new features like supporting booleans +

 	Author: (creator)
	* Gammix

	Contributors:
	* [dRug]Slick - SII code

	(c) Copyright 2015
  	* This file is provided as is (no warranties).
*/

/*
FUNCTIONS:
native ini_exist(filename[]);
native ini_remove(filename[]);
native ini_rename(filename[], newname[]);
native ini_write(filename[], format[], {Float,_}:...);
native ini_read(filename[], format[], {Float,_}:...);
*/

//
#pragma dynamic 45000
//
#define INI_MAX_VALUE 		256 //maximum size of a value of key, can be a string, float, int or bool
#define INI_MAX_KEY 		25 //maximum length of a key's string
#define INI_MAX_LINE_LENGTH 100 //maximum length of one line in a file (key + '=' + value + ';' comment)
#define INI_MAX_FILENAME 	50 //maximum length of a filename's string
#define INI_MAX_LINES 		50 //maximum number of lines or keys a ini file can have

enum CacheEnum
{
	E_KEY[INI_MAX_KEY],
	E_VALUE[INI_MAX_VALUE]
}
static gCache[INI_MAX_LINES][CacheEnum];
static gEmptyCache[CacheEnum];

enum FileEnum
{
	E_FILENAME[INI_MAX_FILENAME],
	bool:E_OPEN
}
static gFile[FileEnum];
static gNoFile[FileEnum];

//internal functions
stock static internal_ini_strcpy(dest[], source[], numcells = sizeof(source), maxlength = sizeof(dest))
{
	new i;
	while ((source[i]) && (i < numcells) && (i < maxlength))
	{
		dest[i] = source[i];
		i ++;
	}
	dest[(i == maxlength) ? (i - 1) : (i)] = '\0';
}

stock static internal_ini_stripnewline(string[])
{
	new l;
	l = strlen(string);
	if (string[l - 2] == '\r') string[l - 2] = '\0';
	if (string[l - 1] == '\n') string[l - 1] = '\0';
}

stock static internal_ini_open(filename[])
{
    if(! filename[0]) return false;
    if(gFile[E_OPEN])
	{
		if(strcmp(gFile[E_FILENAME], filename, true))
		{
			internal_ini_close();
		}
	}
	new File: h;
	h = fopen(filename, io_readwrite);
	if(h)
	{
		internal_ini_strcpy(gFile[E_FILENAME], filename, INI_MAX_FILENAME, INI_MAX_FILENAME);
		new line[INI_MAX_LINE_LENGTH];
		new ln = -1;
		new separator;
		while(((ln + 1) < INI_MAX_LINES) && (fread(h, line)))
		{
			ln ++;
			internal_ini_stripnewline(line);
			separator = strfind(line, "=", false);
			if((line[0] == ';') || (line[0] == '=') || (separator == -1) || (separator > INI_MAX_KEY))
			{
				if(line[0] == ';')
				{
					internal_ini_strcpy(gCache[ln][E_VALUE], line, INI_MAX_VALUE, INI_MAX_VALUE);
				}
				else
				{
					internal_ini_strcpy(gCache[ln][E_VALUE][1], line, INI_MAX_VALUE - 1, INI_MAX_VALUE - 1);
					gCache[ln][E_VALUE][0] = ';';
				}
				continue;
			}
			internal_ini_strcpy(gCache[ln][E_KEY], line, separator, INI_MAX_KEY);
			internal_ini_strcpy(gCache[ln][E_VALUE], line[separator + 1], INI_MAX_VALUE, INI_MAX_VALUE);
			if(! gCache[ln][E_VALUE][0]) gCache[ln][E_VALUE][0] = ' ';
		}
		fclose(h);
		gFile[E_OPEN] = true;
	}
	return true;
}

stock static internal_ini_close()
{
	new File: h;
	h = fopen(gFile[E_FILENAME], io_write);
	if(h)
	{
		new line[INI_MAX_LINE_LENGTH];
		new ln = -1;
		while(((ln + 1) < INI_MAX_LINES) && (gCache[ln + 1][E_VALUE][0]))
		{
			ln ++;
			if(gCache[ln][E_VALUE][0] == ';')
			{
				if(gCache[ln][E_VALUE][1])
				{
					format(line, sizeof(line), "%s\r\n", gCache[ln][E_VALUE]);
					fwrite(h, line);
					continue;
				}
				fwrite(h, "\r\n");
				continue;
			}
			format(line, sizeof(line), "%s=%s\r\n", gCache[ln][E_KEY], gCache[ln][E_VALUE]);
			fwrite(h, line);
		}
		fclose(h);
		return true;
	}

	for (new ln; ln < INI_MAX_LINES; ln++) gCache[ln] = gEmptyCache;
	gFile = gNoFile;
	return true;
}

stock static internal_ini_write(key[], value[])
{
	if(((! key[0]) || key[0] == ';') || (strfind(key, "=", false) != -1)) return false;
	new ln = -1;
	while(((ln + 1) < INI_MAX_LINES) && (gCache[ln + 1][E_VALUE][0]))
	{
		ln ++;
		if(gCache[ln][E_VALUE][0] == ';') continue;
		if(!strcmp(gCache[ln][E_KEY], key, false))
		{
			internal_ini_strcpy(gCache[ln][E_VALUE], value, INI_MAX_VALUE, INI_MAX_VALUE);
			return true;
		}
	}
	ln ++;
	if(ln < INI_MAX_LINES)
	{
		internal_ini_strcpy(gCache[ln][E_KEY], key, INI_MAX_KEY, INI_MAX_KEY);
		internal_ini_strcpy(gCache[ln][E_VALUE], value, INI_MAX_VALUE, INI_MAX_VALUE);
		return true;
	}
	return false;
}

stock static internal_ini_read(key[])
{
	new dest[INI_MAX_VALUE];

	if(! key[0]) return dest;
	new ln = -1;
	while(((ln + 1) < INI_MAX_LINES) && (gCache[ln + 1][E_VALUE][0]))
	{
		ln ++;
		if(gCache[ln][E_VALUE][0] == ';') continue;
		if(!strcmp(gCache[ln][E_KEY], key, false))
		{
			internal_ini_strcpy(dest, gCache[ln][E_VALUE], INI_MAX_VALUE, INI_MAX_VALUE);
			return dest;
		}
	}
	return dest;
}

//main functions
#define ini_exist fexist

stock ini_remove(filename[])
{
	if(! filename[0]) return false;
	if((gFile[E_OPEN]) && (! strcmp(gFile[E_FILENAME], filename, true))) gFile = gNoFile;
	return fremove(filename);
}
#if defined _ALS_fremove
	#undef fremove
#else
	#define _ALS_fremove
#endif
#define fremove ini_remove

stock ini_rename(filename[], newname[])
{
	if(ini_exist(newname)) return false;

	new File: h, File: g, string[INI_MAX_VALUE];
	h = fopen(filename, io_read);
	g = fopen(newname, io_write);

	if(!h) return false;
	if(!g) return (fclose(h));

	while(fread(h, string))
	{
		fwrite(g, string);
	}
	fclose(h);
	fclose(g);
	fremove(filename);
	return true;
}

stock ini_write(filename[], fmat[], {Float,_}:...)
{
    internal_ini_open(filename);

	new index = (0x-1);

    while(++index < strlen(fmat))
    {
        new length = (0x-1), loop = -1, param[0x80];

        while(++length < 0x80)
		{
			param[length] = getarg(2 + (index * 2), length);
        }
		switch(fmat[index])
        {
			case 'b':
			{
			    if(bool:getarg(3 + (index * 2)))
				{
				    internal_ini_write(param, "1");
			 	}
			 	else internal_ini_write(param, "0");
			}
			case 'd', 'i':
			{
			    new dest[12];
				format(dest, sizeof(dest), "%i", getarg(3 + (index * 2)));
				internal_ini_write(param, dest);
			}
			case 'f':
			{
			    new dest[12];
				format(dest, sizeof(dest), "%f", Float:getarg(3 + (index * 2)));
				internal_ini_write(param, dest);
			}
			case 's':
			{
			    new string[INI_MAX_VALUE];
				while(++loop != 0x100)
				{
					string[loop] = getarg(3 + (index * 2), loop);
				}
				internal_ini_write(param, string);
 			}
		}
	}
	return internal_ini_close();
}

stock ini_read(filename[], fmat[], {Float,_}:...)
{
    internal_ini_open(filename);

    new index = (0x-1);

    while(++index < strlen(fmat))
    {
        new length = (0x-1), loop = (0x-1), param[0x80];

        while(++length < 0x80)
		{
			param[length] = getarg(2 + (index * 2), length);
        }
		switch(fmat[index])
	    {
	        case 'b':
			{
				if(strval(internal_ini_read(param)))
				{
					setarg(3 + (index * 2), 0, true);
				}
				else setarg(3 + (index * 2), 0, false);
			}
			case 'd', 'i':
			{
				setarg(3 + (index * 2), 0, strval(internal_ini_read(param)));
			}
			case 'f':
			{
				setarg(3 + (index * 2), 0, _:floatstr(internal_ini_read(param)));
			}
			case 's':
			{
			    new string[INI_MAX_VALUE];
				string = internal_ini_read(param);

				while(strlen(string) != loop++)
				{
					setarg(3 + (index * 2), loop, string[loop]);
  				}
  			}
		}
    }
	return internal_ini_close();
}