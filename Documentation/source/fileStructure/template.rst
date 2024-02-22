.. _templatesDef:

Templates
=========

A **template** file in DaLibrary is a file that holds general C code that may
have multiple static variations. They may have any name and end in .ht, .ct or
.tt, What these files end on depends on what files they template. These files
are meant to be copied and then manually changed.

Contents
--------

These files have the same contents as either:

- :ref:`Headers <headerDef>`, .ht files
- :ref:`Implementations <implementationDef>`, .ct files
- :ref:`Tests <testDef>`, .tt files

Note that they may only have the contents of one of these file types, but not
multiple.
