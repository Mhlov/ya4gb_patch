Yet Another 4Gb Path
====================

Tiny CLI utility that sets the **LARGEADDRESSAWARE** flag on 32-bit Windows
executables, allowing them to use up to **4GB of RAM** on 64-bit systems.


Usage
-----

> [!WARNING]
> It modifies the PE header in-place. Backup your file if you're paranoid.

~~~
ya4gb_patch.exe target_program.exe
~~~


Notes
-----

- Works only on 32-bit `.exe` files.
- On 64-bit Windows, this lifts the default 2GB RAM cap to 4GB.
- On 32-bit systems, it does nothing useful.


License
-------

Licensed under the MIT License.

