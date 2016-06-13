# Python: Basics and Beyond
Adam Rall <arall@buffalo.edu>
Computational Sciences Club
February 4, 2016

## The interpreter
Open an interpreter and show everyone that Python is a useful
calculator, e.g., `2 + 2`, `3 ** 4`, etc.  Stress that Python is an
interpreted language (vs. a compiled one like C, Fortran, etc.).  Ask
who is familiar with a compiled language, an interpreted language
(MATLAB, Ruby, etc.).  If there are many people familiar with
programming, I can speed my talk up.

Note that I will be using Python 3 for this talk.  In addition, I want
to use IPython, a slightly more usable shell for the interpreter.

## Basic types
Python mostly doesn't care what types you use.  Numbers are numbers,
etc.  As long as a given object in Python has the right attributes,
code referencing said object will just work.  For example, `type(1)`
vs. `type(1.0)`; both objects have a way to define addition, so we can
add `1 + 1.0`.  This stuff is pretty straightforward.  When we name a
variable `x = 2; 4 ** x`, we can rename the variable at any time to
any other type we want, e.g., `x = 'hi'`.  If we want to force Python
to use a type, we can cast an object:
    1 + '1'
    1 + int('1')
    str('1') + '1'

## Modules and the standard library
Show people that Python becomes an even more useful calculator with
some pieces of the standard library.  Python code is organized chiefly
into files: each file is called a module, and each module has further
subdivisions of code that we'll talk about later.  A good example of
this is the math module.  After importing it, we can use, e.g., log
and exp.  Show both the `import math` and `from math import log, exp`
versions.  Draw a comparison to Fortran's modules and C/C++'s
`#include` preprocessor directives.  Show that we can use `help()` to
learn more.

## Functions
The pieces of code we imported from the math module--`log` and
`exp`--are examples of functions.  Functions are the first level of
abstraction in Python.  Functions can take any number of arguments of
any kind and return one value (which can actually be a collection).
In simple cases, like `log`, we take one number, apply a mathematical
function to it, and return another number.  We can do whatever we want
inside a function, including importing modules, calling other
functions, defining nested functions, etc.  This is more flexible than
C, C++, Fortran, etc.  We can define a new function with the `def`
keyword.  Note that we use indentation instead of curly braces to
denote changes in scope.  It is important to be consistent here: I
recommend always using 4 spaces.

## Collections
I alluded to the fact that functions can return a collection of items.
Python has several different types of collections built in, including
tuples (fixed-size)
    point = (1, 2)
lists (mutable)
    foods = ['apples', 'bananas', 'oranges', 1.0, 3]
    foods[1]
    foods[-1]
    foods[1:]
    foods[:-1]
dicts (a.k.a. hashtables)
    point = {'x': 1, 'y': 2}
    point['x']
and combinations of the above
    cars = {'mom': 'honda', 'dad': ['toyota', 'ford']}
    cars['dad'][0]

There are other collection types in Python (most notably sets), but
I'm not going to talk about them today.  Collections are integral to
Python.  Because they exist, we can do stuff like
    x, y = 1, 2
    x, y = y, x
or
    def make_point():
        return 1, 2

There are also some nice keywords in Python that work with
collections, like
    'apples' in foods

## Flow control
Python contains the usual set of loops and conditional statements:
    if 'apples' in foods:
        print('We have apples')

    for food in foods:
        print(food.upper())

    i = 0
    while i <= 3:
        print(i + 1)
The canonical way to write C-like for loops in Python is to use
`range`:
    for i in range(3):
        print(i + 1)
If you want both a number and an item from a collection, you can use
`enumerate`:
    for i, food in enumerate(foods):
        print(i, food)

## Classes
Through a combination of Python's built-in types, collections,
modules, and functions we can accomplish a wide range of tasks.  If we
want to write reusable code, we can write our own functions and save
them for later use in our own modules.  There is one last piece of the
basics I have to talk about, and I only want to very briefly mention
it.  We can create our own types by using Python's `class` keyword.
Python is capable of object-oriented programming, just like Java, C++,
and Ruby, but you aren't forced to use it like you are in Java.  To be
honest, I actually prefer simply using the built-in types and just
defining functions.
    class Car(object):
        def __init__(self, name):
            self.wheels = 4
            self.name = name
            self.speed = 0

        def accelerate(amount):
            self.speed += amount


    my_mini = Car('Mini')
    my_mini.accelerate(20)
    print(my_mini.speed)

You can do all sorts of complicated things with objects, like
inheritance.  Note that if you are coming from Java or C++, Python
objects have everything defined to be `public` by default.  This is
how Python programmers like to work!

## Standalone modules
Using standalone modules is the easiest way to save code that you
might want to use again.  You can treat a module like a list of
functions to use in the python interpreter or as a script in bash or a
compiled program.  I'll show you an example of a two modules I've
written that I use in both ways:
- car2xyz.py
- wetting.py

Note that you have to use `if __name__ == '__main__': ...` if you only
want code to run when you call your script like `python script.py`.

## A few tips and tricks
This concludes the "basics" part of the talk.  I'm going to show you a
few intermediate level things and then give you a survey of the
modules that are available in the Python ecosystem.

### List and dict comprehensions
If you have a list of some sort, it is easy to append new items to it:
    people = ['me', 'you', 'them']
    people += ['her']
You might then think that to construct a list of items following some
pattern, the easiest way to do it would be to start with an empty list
and add items as we go along:
    paths = []
    for i in range(4):
        paths += ['r' + str(i + 1)]
This is painfully slow!  The better way to do this is to use list
comprehensions.  List comprehensions allow us to construct a list all
at once using a for loop inside `[]`:
    paths = ['r' + str(i + 1) for i in range(4)]
List comprehensions can have nested `for` loops, `if` statements,
function calls, etc.
    even = [i if i % 2 == 0
            for i in range(10)]
    
    def is_odd(x):
        return i % 2 == 1
    
    odd = [i if is_odd(i)
           for i in range(10)]
The important thing to remember is that list comprehensions have to
have to produce some kind of output, i.e., we can't write
    [print(x) for x in [1, 2, 3]]

I'll note that we can do dict comprehensions too, although there is
usually a better way to do this:
    d = {key: value for (key, value) in iterable}
To give an example using `zip`,
    letters = ['a', 'b', 'c']
    numbers = [1, 2, 3]
    dict(zip(letters, numbers))

### File I/O
For basic file I/O, the most Pythonic way is to use the `with` keyword
and the `open` function:
    with open('file.dat', 'r') as f:
        lines = f.readlines()
Note that this will give a list of strings complete with line
endings.  Then, we can parse the file as necessary:
    for line in lines:
        x, y = line.strip().split()
        x = int(x)
        y = float(y)
We can write lines using `print`:
with open('file2.dat', 'w') as f:
    for line in lines:
        print(line, file=f)
In both of these cases, the file will be automatically closed when the
program exits the `with` block.

### String interpolation using `format()`
There are several ways to do string interpolation, but my favorite is
using the `format` function:
    x = 1
    y = 2
    print('x: {}, y: {}'.format(x, y))
You can introduce all sorts of options to control the format inside
the curly braces.  This is overkill if you don't care too much about
spacing, etc.  Often, you can just write `print('x: ', x)` if you only
have one item.

### Comments and docstrings
Comments are important for describing why code does what it does.  To
add comments to a script, just add the `#` character:
    # This is a comment.
Docstrings are even more important.  I recommend adding them to the
top of each module you write and, optionally, to each function.
Docstrings look like this:
    """This module copies my files to the Desktop."""
    
    def copy_file(file):
        """Copy a given file to the Desktop."""
        pass
Docstrings can span multiple lines and include as much information
about a function as you want.

## Some useful modules in the standard library
Suppose I want to do some scripting that involves copying a file.  I
know that the file is in the current directory, and I want to move the
file to a different directory. I can use the shutil and os.path
modules to do this:
    from shutil import copy
    import os.path
    
    copy('file.dat', os.path.join('..', 'file-copy.dat'))
I can use the `glob` function from the glob module to get a list of
all files matching a given pattern:
    import glob
    
    print(sorted(glob.glob('~/Documents/library/*.pdf')))
I recommend always calling the `sorted` function if you care at all
about what order the results from `glob` are in.  We can use the
random module to get random numbers:
    import random
    
    random.random()
I'll mention here (but won't demonstrate) that Python has extremely
powerful tools for working with things like network connections,
regular expressions, command line arguments, etc.  Although everyone
here is probably more interested in the numerical side of Python, the
langauge is great for automating general computing tasks.

## Some useful numerical modules
Speaking of the numerical side...There are several influential Python
packages for working with data.  You've probably heard of numpy,
scipy, matplotlib, and maybe even pandas, statsmodels, and
scikit-learn.  I'm going to briefly show you what some of these
packages can do. Before I do, I want to mention how to obtain these
packages.  I strongly recommend everyone install Anaconda
(continuum.io), which comes with almost all of these installed by
default.  If you are brave enough, you can install them all manually
using, e.g., dnf, apt, brew, etc.

### Numpy
The people behind numpy and scipy have done a ton of work to make
Python much more appropriate for engineers and scientists to use (as
well as faster).  Although numpy introduces a lot of mathematical
functions, its core element is the array.
    # We have to import numpy to use it; this is the usual way
    import numpy as np
    
    arr = np.array([1, 2, 3])
Arrays are much faster than native Python lists, and they are easier
to work with.  You can make multidimensional arrays:
    arr2 = np.array([[1, 2, 3], [4, 5, 6]])
You can also create arrays using list comprehensions, as described
earlier.  Arrays are nice because you can do element-wise arithmetic
operations on them automatically
    arr2[0] + arr2[1]
You can glean a lot of information about the size, shape, etc. of
arrays
    arr.shape
    arr2.ndim
Arrays can be transposed, reshaped, etc.
    arr2.transpose()
You can even make arrays of complex numbers:
    c = np.array([1+1.1j, 2+0.j, 4-3j])
Numpy introduces quite a few MATLAB-like features:
    x = np.linspace(-np.pi, np.pi, 10)
    np.sin(x)
    np.cos(x)
    y = np.random.random(10)
    y.sum()
    y.min()
    y.max()
It also includes `np.diff, np.cumsum`, etc. and some linear algebra
functions.

We can iterate over arrays:
    # This will iterate over the rows
    for row in arr2:
        print(row + 1)
or slice arrays like normal lists:
    arr2[:, 1:]
Note that numpy contains some useful file I/O functions, most notably
`np.loadtxt` and `np.savetxt`.

### Scipy
There are a ton of numerical functions available in scipy, including
functions for integration, optimization, interpolation, FFT, signal
processing, linear algebra, statistics, etc.  I'll only mention here
that I find the optimization routines (`scipy.optimize`) helpful in my
own work.  I usually use the equivalent of MATLAB's `fsolve` or a
Newton-Raphson solver (`scipy.optimize.newton`).  See
http://docs.scipy.org for more info.

### Matplotlib
Matplotlib is **the** Python plotting library.  It is also very
complex: I could spend a whole hour talking about it and only cover a
small amount of the things it can do.  I'll just give a small example:
    from matplotlib import pyplot as plt
    
    x = np.linspace(-np.pi, np.pi, 100)
    y = np.tan(x)
    plt.plot(x, y, 'o', label=r'$\tan(x)$')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.legend(loc=0)
    plt.show()
We can save our plot if I replace `plt.show()` with, e.g.
    plt.savefig('tan.pdf')
The defaults in matplotlib are a little ugly, but a package called
seaborn does a lot to make things look nicer:
    import seaborn as sns
    
    plt.plot(x, np.sin(x), '-', x, np.cos(x), '--')
    plt.show()

### Pandas, statsmodels, and scikit-learn
The pandas package takes numpy and scipy's work towards making Python
more amenable to data analysis and tacks on a very useful new data
structure called a DataFrame.  DataFrames are basically lifted from R:
they reperesent a table of data with named columns and a ton of
reindexing, reshaping, grouping, and statistical functions.  That
means you can index everything like you would a dict and take, e.g.,
the average of a column.  Additionally, pandas provides tools for
reading and writing csv, tsv, tabular, and HDF5 files.
    import pandas as pd
    
    df = pd.read_csv('data.csv')
    print(df['counts'].mean(), df['counts'].std())
    df.to_tsv('data.tsv')
Statsmodels introduces an easy way to do linear regressions on lists,
numpy arrays, pandas DataFrames.  You can even use the formula syntax
from R if you want!

Finally, scikit-learn lets you do lots of linear regressions at once,
i.e., machine learning.

## IPython/Jupyter
I'd be remiss if I didn't at least mention the capabilities of the
IPython notebook (now Jupyter).  Jupyter functions much like the
notebook interface of Mathematica, allowing you to easily build up a
data analysis or write literate code, i.e., explain what you are doing
as your program progresses.  Jupyter is super helpful for poking data,
aggregating data in different ways, plotting data (in combination with
matplotlib), etc.  It's just like having a running Python interpreter
in the background while you edit your code in a real editor.

IPython also introduces some neat features like `%pylab`, which
automatically imports a ton of stuff from numpy, scipy, and matplotlib
to give you a more MATLAB-like experience.
