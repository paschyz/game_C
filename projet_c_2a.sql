--
-- Database: `projet_c_2a`
--

-- --------------------------------------------------------

--
-- Table structure for table `character`
--

CREATE TABLE `character` (
  `id_character` int(11) NOT NULL,
  `name_character` varchar(32) NOT NULL,
  `HP` int(11) NOT NULL,
  `att` int(11) NOT NULL,
  `Skill` int(11) NOT NULL,
  `type` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `enemies`
--

CREATE TABLE `enemies` (
  `id_enemie` int(11) NOT NULL,
  `name_enemie` int(11) NOT NULL,
  `HP` int(11) NOT NULL,
  `Att` int(11) NOT NULL,
  `type` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Indexes for table `character`
--
ALTER TABLE `character`
  ADD PRIMARY KEY (`id_character`);
COMMIT;


