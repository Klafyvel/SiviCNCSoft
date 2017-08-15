=============
SiviCNCSoft
=============

SiviCNCSoft, a software to control the hardware of my CNC.

:Info: This is a Python program to control a CNC.
:Author: Hugo LEVY-FALK
:Date: 2017-08
:Version: 0.1.0

.. index: README
.. contents:: Table of Contents

------

Goal
====

SiviCNCSoft is intended to be used alongside SiviCNCDriver_ . It controls the hardware of the CNC. It uses a bunch of `custom G-Codes`_.

.. _SiviCNCDriver : https://github.com/Klafyvel/SiviCNCDriver

Custom G-Codes
==============

SiviCNCDriver uses several custom G-Codes, they may change in the future.


+---------------------+--------------------------------------------------------------------------------------------------------------+
|Command              | Explanation                                                                                                  |
+=====================+==============================================================================================================+
|``S0 Xnnn Ynnn Znnn``| Perform a straight line with ``nnn`` in steps on the given axes. A negative number make the axis go backward.|
+---------------------+--------------------------------------------------------------------------------------------------------------+
|``S1 X Y Z``         | Trigger continuous advancement forward on the given axes.                                                    |
+---------------------+--------------------------------------------------------------------------------------------------------------+
|``S2 X Y Z``         | Trigger continuous advancement backward on the given axes.                                                   |
+---------------------+--------------------------------------------------------------------------------------------------------------+
|``S3 X Y Z``         | Stop continuous advancement (if exists) on the given axes.                                                   |
+---------------------+--------------------------------------------------------------------------------------------------------------+
|``S4 Xnnn Ynnn Znnn``| Set the mm/step on the given axes.                                                                           |
+---------------------+--------------------------------------------------------------------------------------------------------------+
|``S5 X Y Z``         | Set driving mode to normal on the given axes.                                                                |
+---------------------+--------------------------------------------------------------------------------------------------------------+
|``S6 X Y Z``         | Set driving mode to max torque on the given axes.                                                            |
+---------------------+--------------------------------------------------------------------------------------------------------------+
|``S7 X Y Z``         | Set driving mode to half steps on the given axes.                                                            |
+---------------------+--------------------------------------------------------------------------------------------------------------+
|``S8 Xnnn Ynnn Znnn``| Set the play of the given axes, with ``nnn`` in millimeters.                                                 |
+---------------------+--------------------------------------------------------------------------------------------------------------+
|``S9 X Y Z``         | Set the given axes sense to reverse.                                                                         |
+---------------------+--------------------------------------------------------------------------------------------------------------+
|``S10 X Y Z``        | Set the given axes sense to normal.                                                                          |
+---------------------+--------------------------------------------------------------------------------------------------------------+


License
=======

SiviCNCDriver
Copyright (C) 2017  Hugo LEVY-FALK

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program.  If not, see <http://www.gnu.org/licenses/>.
