#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jul  1 19:54:40 2019

@author: Hao
"""

from enum import Enum


class Solution:
    # number format [ ]A[.[B]][e|EC][ ] or [ ].B[e|EC][ ]
    # AC are signed int, B is unsigned int
    def isNumber(self, s: str) -> bool:
        if not s:
            return False

        self.index = 0

        # 1. 若干空格
        while self.index < len(s) and s[self.index] == ' ':
            self.index += 1

        if self.index == len(s):
            return False

        def scan_integer():
            # 1.（可选）一个符号字符（'+' 或 '-'）
            if self.index < len(s) and (s[self.index] == '+' or s[self.index] == '-'):
                self.index += 1

            return scan_unsigned_integer()

        def scan_unsigned_integer():
            before = self.index

            while self.index < len(s) and s[self.index] >= '0' and s[self.index] <= '9':
                self.index += 1

            # 2. 至少一位数字
            return self.index > before

        # 2. 一个整数
        # note that it actually scans the sign for decimal as well
        is_numeric = scan_integer()

        # 2. 或者一个小数
        if self.index < len(s) and s[self.index] == '.':
            self.index += 1

            # 1. 至少一位数字，后面跟着一个点 '.'
            # 2. 至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
            # 3. 一个点 '.' ，后面跟着至少一位数字
            # note that need to put scan_unsigned_integer() first
            # otherwise it will not be executed if is_numeric is True
            is_numeric = scan_unsigned_integer() or is_numeric

        if not is_numeric:
            return False

        # 3.（可选）一个 'e' 或 'E' ，后面跟着一个整数
        if self.index < len(s) and (s[self.index] == 'e' or s[self.index] == 'E'):
            self.index += 1

            is_numeric = scan_integer()

        # 4. 若干空格
        while self.index < len(s) and s[self.index] == ' ':
            self.index += 1

        return is_numeric and self.index == len(s)

    # official solution to use deterministic finite automaton
    def isNumber1(self, s: str) -> bool:
        State = Enum("State", [
            "STATE_INITIAL",
            "STATE_INT_SIGN",
            "STATE_INTEGER",
            "STATE_POINT",
            "STATE_POINT_WITHOUT_INT",
            "STATE_FRACTION",
            "STATE_EXP",
            "STATE_EXP_SIGN",
            "STATE_EXP_NUMBER",
            "STATE_END"
        ])
        Chartype = Enum("Chartype", [
            "CHAR_NUMBER",
            "CHAR_EXP",
            "CHAR_POINT",
            "CHAR_SIGN",
            "CHAR_SPACE",
            "CHAR_ILLEGAL"
        ])

        def toChartype(ch: str) -> Chartype:
            if ch.isdigit():
                return Chartype.CHAR_NUMBER
            elif ch.lower() == "e":
                return Chartype.CHAR_EXP
            elif ch == ".":
                return Chartype.CHAR_POINT
            elif ch == "+" or ch == "-":
                return Chartype.CHAR_SIGN
            elif ch == " ":
                return Chartype.CHAR_SPACE
            else:
                return Chartype.CHAR_ILLEGAL

        transfer = {
            State.STATE_INITIAL: {
                Chartype.CHAR_SPACE: State.STATE_INITIAL,
                Chartype.CHAR_NUMBER: State.STATE_INTEGER,
                Chartype.CHAR_POINT: State.STATE_POINT_WITHOUT_INT,
                Chartype.CHAR_SIGN: State.STATE_INT_SIGN
            },
            State.STATE_INT_SIGN: {
                Chartype.CHAR_NUMBER: State.STATE_INTEGER,
                Chartype.CHAR_POINT: State.STATE_POINT_WITHOUT_INT
            },
            State.STATE_INTEGER: {
                Chartype.CHAR_NUMBER: State.STATE_INTEGER,
                Chartype.CHAR_EXP: State.STATE_EXP,
                Chartype.CHAR_POINT: State.STATE_POINT,
                Chartype.CHAR_SPACE: State.STATE_END
            },
            State.STATE_POINT: {
                Chartype.CHAR_NUMBER: State.STATE_FRACTION,
                Chartype.CHAR_EXP: State.STATE_EXP,
                Chartype.CHAR_SPACE: State.STATE_END
            },
            State.STATE_POINT_WITHOUT_INT: {
                Chartype.CHAR_NUMBER: State.STATE_FRACTION
            },
            State.STATE_FRACTION: {
                Chartype.CHAR_NUMBER: State.STATE_FRACTION,
                Chartype.CHAR_EXP: State.STATE_EXP,
                Chartype.CHAR_SPACE: State.STATE_END
            },
            State.STATE_EXP: {
                Chartype.CHAR_NUMBER: State.STATE_EXP_NUMBER,
                Chartype.CHAR_SIGN: State.STATE_EXP_SIGN
            },
            State.STATE_EXP_SIGN: {
                Chartype.CHAR_NUMBER: State.STATE_EXP_NUMBER
            },
            State.STATE_EXP_NUMBER: {
                Chartype.CHAR_NUMBER: State.STATE_EXP_NUMBER,
                Chartype.CHAR_SPACE: State.STATE_END
            },
            State.STATE_END: {
                Chartype.CHAR_SPACE: State.STATE_END
            },
        }

        st = State.STATE_INITIAL
        for ch in s:
            typ = toChartype(ch)
            if typ not in transfer[st]:
                return False
            st = transfer[st][typ]

        return st in [State.STATE_INTEGER, State.STATE_POINT, State.STATE_FRACTION, State.STATE_EXP_NUMBER, State.STATE_END]


mySolution = Solution()
input = '0.8'
result = mySolution.isNumber(input)
print(result)
