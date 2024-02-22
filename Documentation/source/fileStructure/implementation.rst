.. _implementationDef:

Implementation
==============

An **implementation** file in DaLibrary is a file that primarily contains C
definitions. It may also contain declarations, but all of those declarations
must be internal(static). Macro definitions must be undefined by the end of the
file. They may have any name and end in .c. These files are meant to be compiled. 

Contents
--------

Implementation files contain the following, in order:

#. Includes;
#. Macro definitions;
#. Struct forward declarations;
#. Typedefs;
#. Global variable declarations;
#. Struct declarations;
#. Function declarations;
#. Global variable definitions;
#. Function definitions.
