.. _interfaceDef:

Interfaces
==========

Interfaces are the concepts that DaLibrary utilizes to achieve it's flexibility.
In essence an interface is just a plain old C struct that holds function
pointers with a bunch of constraints and requirements.

There exist 2 types of interfaces:

- :ref:`Simple interfaces <simpleInterfaceDef>`
- :ref:`Complex interfaces <complexInterfaceDef>`

.. _interfaceUserDef:
.. _interfaceProviderDef:

.. //TODO:

.. _interfaceConstrainsDef:

Constraints
-----------

.. warning:: If any of these constraints are not followed, expect fatal program errors.

Interface structs may not be copied. They however may be moved. Moving is done
by copying all of the pointers from one interface to another interface of the
same type. The original interface's pointers are then all set to null.

The interface may not be mutated by a :ref:`user <interfaceUserDef>` of said
interface. Only the :ref:`provider <interfaceProviderDef>` may mutate it.

.. _interfaceRequirementsDef:

Requirements
------------

Interfaces must always be both readable and writable. Each member of the
interface struct may be mutated by the :ref:`provider <interfaceProviderDef>`.

.. _simpleInterfaceDef:

Simple interfaces
-----------------

A simple interface is a structure that has:

- As its first member a void pointer called State;
- 1 or more function pointers after the first member. Each function pointer
  must take a pointer to the simple interface itself in the argument list.

A simple interface may also have, but doesn't need to:

- A :ref:`Size <mod:Fundamental:Size>` and a variable-length array of function
  pointers as the last members;

.. _complexInterfaceDef:

Interface functions
-------------------



Complex interfaces
------------------
