.. _funcNamingDef:

Function naming
===============

Functions in DaLibrary, :ref:`among other things <todo>`, must follow a system
that is used to determent their name.

The reason there is a system in place for this is so that, with just the 
function name the following can be inferred:

.. _funcNamingGoals:

- What the function does;
- What arguments, in what order, and what those arguments are used for by the
  function;
- The return value and how it relates to what the function does;

.. _funcNamingShort:

In essence this is achieved by splitting function names into 
:ref:`two groups <funcNamingGroups>` that differ by whether they do something
or check something. Then in both function names
:ref:`the argument list is encoded <funcNamingArgs>`. The specifics about how
it the argument list is encoded differ between the two groups. And at last each 
function name group has specific things that may be added to further elaborate 
the above 3 goals.

.. _funcNamingGroups:

Groups
------

There are 2 groups of function names:

- Commands;
- Statements;

Commands
++++++++

Command functions are the group of functions that do something. Their name looks
like an imperative sentence, hence their name. They are comprised of the
following:

#. Action;
#. Argument list;
#. Elaboration.

These 3 parts are appended to each other in the following way:

<Action><Argument list>_<Elaboration>

The action comes first, then the argument list is appended right next to it and
finally an underscore is appended to the argument list, to which the elaboration
is appended to.

Action
******

The action is a single word that denotes what the function does. Additionally
each action provides information about how each argument is used, but that is
depended upon the action.
:ref:`List of all actions along with what they do <funcNamingActionList>`.

Statements
++++++++++

Argument list
-------------

The argument list is a shared feature of both
:ref:`function name groups <funcNamingGroups>`. Do keep in mind that each
group has multiple additional things that need to be specified.

However in general the argument list is specified going from the first argument
of a function to the last. Each argument has its type written and an optional
comment. The comment is appended to the end of the type and the type and comment
are separated with a literal `As`.

Comment
+++++++

The comment is an optional 

Example
+++++++

For example lets take the following function:

.. code-block:: C
    int foo(int p_num1, float p_num2, void* p_buffer, int p_size);

If we were to generate an argument list for this function it would look like 
this:

.. code-block::
    IntAsLeftFloatAsRightVoidPointerAsBufferIntAsBufferSize