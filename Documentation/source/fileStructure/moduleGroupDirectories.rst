.. _moduleGroupDirDef:

Module group directories
========================

A **module group directory** is a directory belonging to a
:ref:`module group <moduleGroupDef>` that holds
:ref:`module directories <moduleDirDef>`. A single
:ref:`module group <moduleGroupDef>` may have multiple module group directories
:term:`below` different :ref:`main directories <mainDirDef>`. If a
:ref:`module group <moduleGroupDef>` does not have any files that belong to a
:ref:`main directory <mainDirDef>`, then it does not have a module group
directory :term:`below` that :ref:`main directory <mainDirDef>`.

Properties
----------

Module group directories have the following properties:

- They have the same name as the :ref:`module group <moduleGroupDef>` that owns
  them, with the same :ref:`spelling <spellingDef>`;
- They are held either:
   - :term:`below` the :ref:`main directories <mainDirDef>`;
   - :term:`under` another :ref:`module group directory <moduleGroupDirDef>`.

Contents
--------

Module group directories contain the following:

- :ref:`A include-all-file <includeAllFileDef>`;
- :ref:`Module directories <moduleDirDef>` that are owned by
  :ref:`modules <moduleDef>` that are a part of the
  :ref:`module group <moduleGroupDef>` that owns the module group directory.
- Other :ref:`Module group directories <moduleGroupDirDef>` that are owned by
  :ref:`module groups <moduleGroupDef>` that are a part of the
  :ref:`module group <moduleGroupDef>` that owns the module group directory.

Example
-------

For example the Foo :ref:`module <moduleDef>`, which is a part of the Bar
:ref:`module group <moduleGroupDef>`, would have a
:ref:`module directory <moduleDirDef>` named Foo. The Bar
:ref:`module group <moduleGroupDef>` also has a second :ref:`module <moduleDef>`
named Biz, which also has its own :ref:`module directory <moduleDirDef>`.
Finally, the Bar directory contains its
:ref:`include-all-file <includeAllFileDef>` with an appropriate file extension.