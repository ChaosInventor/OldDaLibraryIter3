.. _includeAllFileDef:

Include-all-file
================

An **include-all-file** is a file that uses the C preprocessor to #include all
other files that are :term:`under` the directory that the include-all-file is
:term:`under`. This does not only apply to headers, but to all files.

.. note:: Include-all-files do not have a :ref:`header guard <headerGuardDef>`


Properties
----------

Name
++++

The name of an include-all-file is the same as the name of the directory it is 
:term:`under`, with the same :ref:`spelling <spellingDef>`.

The only exception to this is if the include-all-file is :term:`under` any of
the :ref:`main directories <mainDirDef>`, in which case the include-all-file has
the name DaLibrary.

File extension
++++++++++++++

Include-all-files have a file extension appropriate for the
:ref:`main directory <mainDirDef>` they are :term:`below`.