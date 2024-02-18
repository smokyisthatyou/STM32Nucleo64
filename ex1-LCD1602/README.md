# Example with LCD



## Overview

The display 1602 is a versatile output interface on the which two-line messages can be displayed from 16 characters.
Some of the functionality of the 16 display pins are illustrated in following table:


<table>
<tr><td>Pin number </td><td>Function </td></tr>
<tr><td>1 </td><td>VSS gnd</td></tr>
<tr><td>2 </td><td>VDD 5V</td></tr>
<tr><td>3 </td><td>V0 </td></tr>
<tr><td>4 </td><td>RS register select high=data low=instructions </td></tr>
<tr><td>5 </td><td>R/W High=R; Low=W </td></tr>
<tr><td>6 </td><td>High=enable byte input </td></tr>
<tr><td>15 </td><td>BL-A (5volt) </td></tr>
<tr><td>16 </td><td>BL-K (gnd) </td></tr>
</table>


In general it is possible to say that the configuration of pins 7 to 14 (which can be HIGH or LOW i.e. 0 or 1) represents the byte that are intended to display. The display receives, stores in a register and displays the byte following the instructions given to it through pins 4, 5 and 6.

## Setup
