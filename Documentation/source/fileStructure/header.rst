.. _headerDef:

Header
======

A **header** file in DaLibrary is a file that exclusively contains C
declarations. They may have any name and always end in .h. These files are meant
to be included by other files.

Contents
--------

Each header contains the following, in order:

#. :ref:`Header guard <headerGuardDef>`;
#. Includes;
#. Macro definitions;
#. Struct forward declarations and typedefs;
#. Global variable declarations;
#. Struct declarations;
#. Function declarations

.. _headerGuardDef:

Header guard
++++++++++++

A header guard is a #ifndef preprocessor directive that surrounds the entire
header.

The purpose of this directive is to ensure that the contents of the header file
are only defined once, even if the header file is included multiple times.

This is achieved by defining a macro with a systematic name and having
the #ifndef directive check if it has been defined. The header guard macro is
defined, the contents of the header file are not defined, otherwise
the header's contents are defined along side the header guard macro.

The macro is :ref:`spelled <spellingDef>` in
:ref:`YELLING_SNAKE_CASE <spellingYelSnakeCase>` and has
the following name:

<name of :ref:`module <moduleDef>` that the header file belongs to>__<path to
file where every path separator is replaced with a _, not including the
:ref:`project directory <projectDirDef>` or the
:ref:`main directories <mainDirDef>` and including the file name where .h
becomes _H>

Variations
----------

Headers have 2 variations that are stored in different
:ref:`main directories <mainDirDef>`:

- :ref:`Public headers <publicHeaderDef>`;
- :ref:`Private headers <privateHeaderDef>`.

.. _publicHeaderDef:

Public header
+++++++++++++

A **public header** is a :ref:`header <headerDef>` that is meant to be used
both internally and externally. Projects that wish to use DaLibrary should
include these headers.

Public headers only include other public headers. They do not include 
:ref:`private headers <privateHeaderDef>`.

Public headers are stored :term:`below` the PublicInclude/
:ref:`main directory <mainDirDef>`.

.. _privateHeaderDef:

Private header
++++++++++++++

A **private header** is a :ref:`header <headerDef>` that is meant to be used
only internally. Projects that wish to use DaLibrary must not include these
files.

The :ref:`header guard <headerGuardDef>` for private headers has a __P appended
to the end of its macro. They include both other private headers and
:ref:`public headers <publicHeaderDef>`

Private headers are stored :term:`below` the PrivateInclude/
:ref:`main directory <mainDirDef>`.
