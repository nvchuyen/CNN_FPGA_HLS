-- ==============================================================
-- Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
-- Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity cnn_fc_layer2_weights_rom is 
    generic(
             DWIDTH     : integer := 32; 
             AWIDTH     : integer := 5; 
             MEM_SIZE    : integer := 20
    ); 
    port (
          addr0      : in std_logic_vector(AWIDTH-1 downto 0); 
          ce0       : in std_logic; 
          q0         : out std_logic_vector(DWIDTH-1 downto 0);
          clk       : in std_logic
    ); 
end entity; 


architecture rtl of cnn_fc_layer2_weights_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 => "00111111000110001010110110101100", 
    1 => "00111110101011000010001001101000", 
    2 => "00111111000101100010101101101011", 
    3 => "10111111000111000010100011110110", 
    4 => "00111111000111001111010000011111", 
    5 => "10111111000100110101101010000110", 
    6 => "10111110111001001101000000010100", 
    7 => "00111111001010010010101000110000", 
    8 => "00111111010011001001000111010001", 
    9 => "10111111000100010001001101000000", 
    10 => "10111110011010000111001010110000", 
    11 => "00111111010010101001100100110001", 
    12 => "10111110100010001101101110001100", 
    13 => "00111110011010110001110001000011", 
    14 => "10111110100001001010100011000001", 
    15 => "00111110101101100110110011110100", 
    16 => "10111110100010111001001000111010", 
    17 => "10111101011110111110011101101101", 
    18 => "10111111010000011100010000110011", 
    19 => "00111111000011010111011100110010" );


begin 


memory_access_guard_0: process (addr0) 
begin
      addr0_tmp <= addr0;
--synthesis translate_off
      if (CONV_INTEGER(addr0) > mem_size-1) then
           addr0_tmp <= (others => '0');
      else 
           addr0_tmp <= addr0;
      end if;
--synthesis translate_on
end process;

p_rom_access: process (clk)  
begin 
    if (clk'event and clk = '1') then
        if (ce0 = '1') then 
            q0 <= mem(CONV_INTEGER(addr0_tmp)); 
        end if;
    end if;
end process;

end rtl;

Library IEEE;
use IEEE.std_logic_1164.all;

entity cnn_fc_layer2_weights is
    generic (
        DataWidth : INTEGER := 32;
        AddressRange : INTEGER := 20;
        AddressWidth : INTEGER := 5);
    port (
        reset : IN STD_LOGIC;
        clk : IN STD_LOGIC;
        address0 : IN STD_LOGIC_VECTOR(AddressWidth - 1 DOWNTO 0);
        ce0 : IN STD_LOGIC;
        q0 : OUT STD_LOGIC_VECTOR(DataWidth - 1 DOWNTO 0));
end entity;

architecture arch of cnn_fc_layer2_weights is
    component cnn_fc_layer2_weights_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    cnn_fc_layer2_weights_rom_U :  component cnn_fc_layer2_weights_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


