# -*- coding: utf-8 -*-

"""Top-level package for abletonlink."""

__author__ = """Gabriele Barbieri"""
__email__ = 'gabriele.barbieri83@gmail.com'
__version__ = '0.1.0'

try:
    from .abletonlink import Link
    __ALL__ = [Link]
except ImportError as e:
    print('No module named abletonlink')
    print('Are you sure that you built it?')
