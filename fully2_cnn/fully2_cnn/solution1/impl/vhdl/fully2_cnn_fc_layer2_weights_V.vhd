-- ==============================================================
-- Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
-- Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity fully2_cnn_fc_layer2_weights_V_rom is 
    generic(
             DWIDTH     : integer := 25; 
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


architecture rtl of fully2_cnn_fc_layer2_weights_V_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 => "0100110001010110110101011", 1 => "0010101100001000100110100", 
    2 => "0100101100010101101101010", 3 => "1011000111101011100001010", 
    4 => "0100111001111010000011111", 5 => "1011011001010010101111010", 
    6 => "1100011011001011111110110", 7 => "0101010010010101000110000", 
    8 => "0110011001001000111010001", 9 => "1011011101110110010111111", 
    10 => "1110001011110001101010011", 11 => "0110010101001100100110000", 
    12 => "1101110111001001000111010", 13 => "0001110101100011100010000", 
    14 => "1101111011010101110011111", 15 => "0010110110011011001111010", 
    16 => "1101110100011011011100010", 17 => "1111100000100000110001001", 
    18 => "1001111100011101111001101", 19 => "0100011010111011100110001" );


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

entity fully2_cnn_fc_layer2_weights_V is
    generic (
        DataWidth : INTEGER := 25;
        AddressRange : INTEGER := 20;
        AddressWidth : INTEGER := 5);
    port (
        reset : IN STD_LOGIC;
        clk : IN STD_LOGIC;
        address0 : IN STD_LOGIC_VECTOR(AddressWidth - 1 DOWNTO 0);
        ce0 : IN STD_LOGIC;
        q0 : OUT STD_LOGIC_VECTOR(DataWidth - 1 DOWNTO 0));
end entity;

architecture arch of fully2_cnn_fc_layer2_weights_V is
    component fully2_cnn_fc_layer2_weights_V_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    fully2_cnn_fc_layer2_weights_V_rom_U :  component fully2_cnn_fc_layer2_weights_V_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


