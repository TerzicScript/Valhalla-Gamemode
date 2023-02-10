-- phpMyAdmin SQL Dump
-- version 3.4.5
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Nov 11, 2011 at 08:10 PM
-- Server version: 5.5.16
-- PHP Version: 5.3.8

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `sa:mp`
--

-- --------------------------------------------------------

--
-- Table structure for table `house`
--

CREATE TABLE IF NOT EXISTS `house` (
  `User` varchar(24) NOT NULL,
  `EnterX` float NOT NULL,
  `EnterY` float NOT NULL,
  `EnterZ` float NOT NULL,
  `ExitX` float NOT NULL,
  `ExitY` float NOT NULL,
  `ExitZ` float NOT NULL,
  `Interior` int(11) NOT NULL,
  `Price` int(11) NOT NULL,
  `VirtualWorld` int(11) NOT NULL,
  `Owned` int(11) NOT NULL,
  `Locked` int(11) NOT NULL,
  `Alarm` int(11) NOT NULL,
  `Weapon ID 1` int(11) NOT NULL,
  `Weapon ID 2` int(11) NOT NULL,
  `Weapon ID 3` int(11) NOT NULL,
  `Weapon ID 1 Ammo` int(11) NOT NULL,
  `Weapon ID 2 Ammo` int(11) NOT NULL,
  `Weapon ID 3 Ammo` int(11) NOT NULL,
  `Money` int(11) NOT NULL,
  `Rent User` varchar(24) NOT NULL,
  `Rent Price` int(11) NOT NULL,
  `Rented` int(11) NOT NULL,
  `Rent Disabled` int(11) NOT NULL,
  `VehicleID` int(11) NOT NULL,
  `CarX` float NOT NULL,
  `CarY` float NOT NULL,
  `CarZ` float NOT NULL,
  `CarA` float NOT NULL,
  `Color1` int(11) NOT NULL,
  `Color2` int(11) NOT NULL,
  `Car Locked` int(11) NOT NULL,
  `Car Owner` varchar(24) NOT NULL,
  `Car Weapon ID 1` int(11) NOT NULL,
  `Car Weapon ID 2` int(11) NOT NULL,
  `Car Weapon ID 1 Ammo` int(11) NOT NULL,
  `Car Weapon ID 2 Ammo` int(11) NOT NULL,
  `Car Money` int(11) NOT NULL,
  `HouseID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
