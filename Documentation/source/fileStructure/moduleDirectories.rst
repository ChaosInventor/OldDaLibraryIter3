.. _moduleDirDef:

Module directories
==================

A **module directory** is a directory that holds the files of a single
:ref:`module <moduleDef>`. A single :ref:`module <moduleDef>` may have multiple
module directories that are :term:`below` different
:ref:`main directories <mainDirDef>`. If a :ref:`module <moduleDef>` does not
have any files that belong to a :ref:`main directory <mainDirDef>` then it does
not have a module directory in that :ref:`main directory <mainDirDef>`

Properties
----------

Module directories have the following properties:

- They have the same name as the :ref:`module <moduleDef>` that owns them, with
  the same :ref:`spelling <spellingDef>`;
- They are held either:
  
  - :term:`below` the :ref:`main directories <mainDirDef>`;
  - :term:`under` a :ref:`module group directory <moduleGroupDirDef>`.

Contents
--------

Module directories contain the following:

- :ref:`A include-all-file <includeAllFileDef>`;
- Files that belong to the owning :ref:`module <moduleDef>` and are appropriate
  for the :ref:`main directory <mainDirDef>` that the module directory is
  :term:`below`.

Example
-------

For example the Foo :ref:`module <moduleDef>` would have multiple directories
named Foo/. Each of these Foo directories would then be distributed across
multiple :ref:`main directories <mainDirDef>`. Each of these directories then
holds the appropriate files for the :ref:`main directory <mainDirDef>` it
is :term:`below`. Finally, the Foo directory contains its
:ref:`include-all-file <includeAllFileDef>` with an appropriate file extension.