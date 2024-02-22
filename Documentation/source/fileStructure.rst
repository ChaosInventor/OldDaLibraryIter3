The file structure of DaLibrary
===============================

.. _dirDef:

Directories
-----------

If you are interested about the file structure of DaLibrary start reading about
the :ref:`project directory <projectDirDef>`.

DaLibrary has multiple different types of **directories**:

.. toctree::
  :maxdepth: 1

  Project directory <fileStructure/projectDirectory.rst>
  Main directories <fileStructure/mainDirectories.rst>
  Module directories <fileStructure/moduleDirectories.rst>
  Module group directories <fileStructure/moduleGroupDirectories.rst>  

.. _filesDef:

Files
-----

DaLibrary has multiple different types of **files**:

.. toctree::
    :maxdepth: 1

    Headers <fileStructure/header.rst>
    Implementations <fileStructure/implementation.rst>
    Templates <fileStructure/template.rst>
    Examples <fileStructure/example.rst>
    Tests <fileStructure/test.rst>
    Documentation <fileStructure/documentation.rst>

Files, depending on their type, are :term:`below` the
:ref:`main directories <mainDirDef>`. Special files that are :term:`under` the
:ref:`project directory` are not covered by this documentation.

.. //TODO: Put these targets where they need to be.

.. _moduleDef:
.. _moduleGroupDef:
.. _spellingDef:
.. _examples:
.. _spellingYelSnakeCase:

Directory terms
---------------

In order to make talking about directory structure easier the following terms
have been defined:

.. glossary::

  below
    A directory, A, is said to be below another directory, B, if A is a
    subdirectory of B with any number of indirections. That is, any of
    the following are valid file paths: B/C/D/E/A, B/R/A, B/A
    
  under
    A directory, A, is said to be under another directory, B, if A is a **direct**
    subdirectory of B. That is the only valid way to reach A from B is B/A.
