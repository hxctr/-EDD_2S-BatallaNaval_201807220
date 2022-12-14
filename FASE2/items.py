# This file was automatically generated by SWIG (http://www.swig.org).
# Version 4.0.1
#
# Do not make changes to this file unless you know what you are doing--modify
# the SWIG interface file instead.

from sys import version_info as _swig_python_version_info
if _swig_python_version_info < (2, 7, 0):
    raise RuntimeError("Python 2.7 or later required")

# Import the low-level C/C++ module
if __package__ or "." in __name__:
    from . import _items
else:
    import _items

try:
    import builtins as __builtin__
except ImportError:
    import __builtin__

def _swig_repr(self):
    try:
        strthis = "proxy of " + self.this.__repr__()
    except __builtin__.Exception:
        strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)


def _swig_setattr_nondynamic_instance_variable(set):
    def set_instance_attr(self, name, value):
        if name == "thisown":
            self.this.own(value)
        elif name == "this":
            set(self, name, value)
        elif hasattr(self, name) and isinstance(getattr(type(self), name), property):
            set(self, name, value)
        else:
            raise AttributeError("You cannot add instance attributes to %s" % self)
    return set_instance_attr


def _swig_setattr_nondynamic_class_variable(set):
    def set_class_attr(cls, name, value):
        if hasattr(cls, name) and not isinstance(getattr(cls, name), property):
            set(cls, name, value)
        else:
            raise AttributeError("You cannot add class attributes to %s" % cls)
    return set_class_attr


def _swig_add_metaclass(metaclass):
    """Class decorator for adding a metaclass to a SWIG wrapped class - a slimmed down version of six.add_metaclass"""
    def wrapper(cls):
        return metaclass(cls.__name__, cls.__bases__, cls.__dict__.copy())
    return wrapper


class _SwigNonDynamicMeta(type):
    """Meta class to enforce nondynamic attributes (no new attributes) for a class"""
    __setattr__ = _swig_setattr_nondynamic_class_variable(type.__setattr__)


class SwigPyIterator(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")

    def __init__(self, *args, **kwargs):
        raise AttributeError("No constructor defined - class is abstract")
    __repr__ = _swig_repr
    __swig_destroy__ = _items.delete_SwigPyIterator

    def value(self):
        return _items.SwigPyIterator_value(self)

    def incr(self, n=1):
        return _items.SwigPyIterator_incr(self, n)

    def decr(self, n=1):
        return _items.SwigPyIterator_decr(self, n)

    def distance(self, x):
        return _items.SwigPyIterator_distance(self, x)

    def equal(self, x):
        return _items.SwigPyIterator_equal(self, x)

    def copy(self):
        return _items.SwigPyIterator_copy(self)

    def next(self):
        return _items.SwigPyIterator_next(self)

    def __next__(self):
        return _items.SwigPyIterator___next__(self)

    def previous(self):
        return _items.SwigPyIterator_previous(self)

    def advance(self, n):
        return _items.SwigPyIterator_advance(self, n)

    def __eq__(self, x):
        return _items.SwigPyIterator___eq__(self, x)

    def __ne__(self, x):
        return _items.SwigPyIterator___ne__(self, x)

    def __iadd__(self, n):
        return _items.SwigPyIterator___iadd__(self, n)

    def __isub__(self, n):
        return _items.SwigPyIterator___isub__(self, n)

    def __add__(self, n):
        return _items.SwigPyIterator___add__(self, n)

    def __sub__(self, *args):
        return _items.SwigPyIterator___sub__(self, *args)
    def __iter__(self):
        return self

# Register SwigPyIterator in _items:
_items.SwigPyIterator_swigregister(SwigPyIterator)

class IntVector(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")
    __repr__ = _swig_repr

    def iterator(self):
        return _items.IntVector_iterator(self)
    def __iter__(self):
        return self.iterator()

    def __nonzero__(self):
        return _items.IntVector___nonzero__(self)

    def __bool__(self):
        return _items.IntVector___bool__(self)

    def __len__(self):
        return _items.IntVector___len__(self)

    def __getslice__(self, i, j):
        return _items.IntVector___getslice__(self, i, j)

    def __setslice__(self, *args):
        return _items.IntVector___setslice__(self, *args)

    def __delslice__(self, i, j):
        return _items.IntVector___delslice__(self, i, j)

    def __delitem__(self, *args):
        return _items.IntVector___delitem__(self, *args)

    def __getitem__(self, *args):
        return _items.IntVector___getitem__(self, *args)

    def __setitem__(self, *args):
        return _items.IntVector___setitem__(self, *args)

    def pop(self):
        return _items.IntVector_pop(self)

    def append(self, x):
        return _items.IntVector_append(self, x)

    def empty(self):
        return _items.IntVector_empty(self)

    def size(self):
        return _items.IntVector_size(self)

    def swap(self, v):
        return _items.IntVector_swap(self, v)

    def begin(self):
        return _items.IntVector_begin(self)

    def end(self):
        return _items.IntVector_end(self)

    def rbegin(self):
        return _items.IntVector_rbegin(self)

    def rend(self):
        return _items.IntVector_rend(self)

    def clear(self):
        return _items.IntVector_clear(self)

    def get_allocator(self):
        return _items.IntVector_get_allocator(self)

    def pop_back(self):
        return _items.IntVector_pop_back(self)

    def erase(self, *args):
        return _items.IntVector_erase(self, *args)

    def __init__(self, *args):
        _items.IntVector_swiginit(self, _items.new_IntVector(*args))

    def push_back(self, x):
        return _items.IntVector_push_back(self, x)

    def front(self):
        return _items.IntVector_front(self)

    def back(self):
        return _items.IntVector_back(self)

    def assign(self, n, x):
        return _items.IntVector_assign(self, n, x)

    def resize(self, *args):
        return _items.IntVector_resize(self, *args)

    def insert(self, *args):
        return _items.IntVector_insert(self, *args)

    def reserve(self, n):
        return _items.IntVector_reserve(self, n)

    def capacity(self):
        return _items.IntVector_capacity(self)
    __swig_destroy__ = _items.delete_IntVector

# Register IntVector in _items:
_items.IntVector_swigregister(IntVector)

class StringVector(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")
    __repr__ = _swig_repr

    def iterator(self):
        return _items.StringVector_iterator(self)
    def __iter__(self):
        return self.iterator()

    def __nonzero__(self):
        return _items.StringVector___nonzero__(self)

    def __bool__(self):
        return _items.StringVector___bool__(self)

    def __len__(self):
        return _items.StringVector___len__(self)

    def __getslice__(self, i, j):
        return _items.StringVector___getslice__(self, i, j)

    def __setslice__(self, *args):
        return _items.StringVector___setslice__(self, *args)

    def __delslice__(self, i, j):
        return _items.StringVector___delslice__(self, i, j)

    def __delitem__(self, *args):
        return _items.StringVector___delitem__(self, *args)

    def __getitem__(self, *args):
        return _items.StringVector___getitem__(self, *args)

    def __setitem__(self, *args):
        return _items.StringVector___setitem__(self, *args)

    def pop(self):
        return _items.StringVector_pop(self)

    def append(self, x):
        return _items.StringVector_append(self, x)

    def empty(self):
        return _items.StringVector_empty(self)

    def size(self):
        return _items.StringVector_size(self)

    def swap(self, v):
        return _items.StringVector_swap(self, v)

    def begin(self):
        return _items.StringVector_begin(self)

    def end(self):
        return _items.StringVector_end(self)

    def rbegin(self):
        return _items.StringVector_rbegin(self)

    def rend(self):
        return _items.StringVector_rend(self)

    def clear(self):
        return _items.StringVector_clear(self)

    def get_allocator(self):
        return _items.StringVector_get_allocator(self)

    def pop_back(self):
        return _items.StringVector_pop_back(self)

    def erase(self, *args):
        return _items.StringVector_erase(self, *args)

    def __init__(self, *args):
        _items.StringVector_swiginit(self, _items.new_StringVector(*args))

    def push_back(self, x):
        return _items.StringVector_push_back(self, x)

    def front(self):
        return _items.StringVector_front(self)

    def back(self):
        return _items.StringVector_back(self)

    def assign(self, n, x):
        return _items.StringVector_assign(self, n, x)

    def resize(self, *args):
        return _items.StringVector_resize(self, *args)

    def insert(self, *args):
        return _items.StringVector_insert(self, *args)

    def reserve(self, n):
        return _items.StringVector_reserve(self, n)

    def capacity(self):
        return _items.StringVector_capacity(self)
    __swig_destroy__ = _items.delete_StringVector

# Register StringVector in _items:
_items.StringVector_swigregister(StringVector)

NOT_FOUND = _items.NOT_FOUND
class NodoArticulo(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")
    __repr__ = _swig_repr
    nombre = property(_items.NodoArticulo_nombre_get, _items.NodoArticulo_nombre_set)
    id = property(_items.NodoArticulo_id_get, _items.NodoArticulo_id_set)
    precio = property(_items.NodoArticulo_precio_get, _items.NodoArticulo_precio_set)
    categoria = property(_items.NodoArticulo_categoria_get, _items.NodoArticulo_categoria_set)
    src_img = property(_items.NodoArticulo_src_img_get, _items.NodoArticulo_src_img_set)
    next = property(_items.NodoArticulo_next_get, _items.NodoArticulo_next_set)

    def __init__(self, id, categoria, nombre, precio, src_img):
        _items.NodoArticulo_swiginit(self, _items.new_NodoArticulo(id, categoria, nombre, precio, src_img))
    __swig_destroy__ = _items.delete_NodoArticulo

# Register NodoArticulo in _items:
_items.NodoArticulo_swigregister(NodoArticulo)

class ListaArticulos(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")
    __repr__ = _swig_repr

    def __init__(self):
        _items.ListaArticulos_swiginit(self, _items.new_ListaArticulos())

    def insert(self, id, categoria, nombre, precio, src_img):
        return _items.ListaArticulos_insert(self, id, categoria, nombre, precio, src_img)

    def returnIdByName(self, nombre):
        return _items.ListaArticulos_returnIdByName(self, nombre)

    def sendIdsToPY(self):
        return _items.ListaArticulos_sendIdsToPY(self)

    def sendCategoriaToPY(self):
        return _items.ListaArticulos_sendCategoriaToPY(self)

    def sendPrecioToPY(self):
        return _items.ListaArticulos_sendPrecioToPY(self)

    def sendNombreToPY(self):
        return _items.ListaArticulos_sendNombreToPY(self)

    def sendSRCToPY(self):
        return _items.ListaArticulos_sendSRCToPY(self)

    def _print(self):
        return _items.ListaArticulos__print(self)

    def deleteList(self, head):
        return _items.ListaArticulos_deleteList(self, head)
    __swig_destroy__ = _items.delete_ListaArticulos

# Register ListaArticulos in _items:
_items.ListaArticulos_swigregister(ListaArticulos)



