#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jul  1 19:54:40 2019

@author: Hao
"""


class Solution:
    # DFS to search the nondeterministic finite-state machine, however, it will timeout
    def isMatch1(self, s: str, p: str) -> bool:
        if s is None or p is None:
            return False

        s_length, p_length = len(s), len(p)

        def dfs(s_index, p_index):
            # both reach the end
            if p_index == p_length and s_index == s_length:
                return True

            # only pattern reaches the end
            if p_index == p_length and s_index < s_length:
                return False

            # pay attention to the empty string check
            is_current_match = (s_index < s_length
                                and (s[s_index] == p[p_index] or p[p_index] == '.'))
            if p_index + 1 < p_length and p[p_index + 1] == '*':
                if is_current_match:
                    return (dfs(s_index + 1, p_index + 2)  # move to the next state
                            or dfs(s_index + 1, p_index)  # stay on the current state
                            or dfs(s_index, p_index + 2))  # ignore the '*'
                else:
                    return dfs(s_index, p_index + 2)  # ignore the '*'

            if is_current_match:
                return dfs(s_index + 1, p_index + 1)

            return False

        return dfs(0, 0)

    # DP
    # f[i][j] => if s[0, i - 1] matches p[0, j - 1]
    # initial f[0][0] = True, , target f[len(s)][len(p)]
    # f[i][j] = { if (p[j-1] != '*') = { f[i−1][j−1] if matches(s[i-1],p[j-1]); false, otherwise };
    #             otherwise = { f[i−1][j] or f[i][j−2] if matches(s[i-1],p[j−2]); f[i][j−2], otherwise }}
    def isMatch(self, s: str, p: str) -> bool:
        if s is None or p is None:
            return False

        s_length, p_length = len(s), len(p)

        def matches(i: int, j: int) -> bool:
            if p[j] == '.':
                return True

            return s[i] == p[j]

        # initialisation
        f = [[False] * (p_length + 1) for _ in range(s_length + 1)]
        f[0][0] = True
        for j in range(2, p_length + 1):
            f[0][j] = f[0][j - 2] and p[j - 1] == '*'

        # state transition
        for i in range(1, s_length + 1):
            for j in range(1, p_length + 1):
                if p[j - 1] == '*':
                    f[i][j] |= f[i][j - 2]

                    if s[i - 1] == p[j - 2] or p[j - 2] == '.':
                        f[i][j] |= f[i - 1][j]
                else:
                    if s[i - 1] == p[j - 1] or p[j - 1] == '.':
                        f[i][j] |= f[i - 1][j - 1]

        return f[s_length][p_length]


mySolution = Solution()
input1 = 'ab'
input2 = '.*c'
result = mySolution.isMatch(input1, input2)
print(result)

input1 = 'aaaaaaaaaaaaab'
input2 = 'a*a*a*a*a*a*a*a*a*a*c'
result = mySolution.isMatch(input1, input2)
print(result)
