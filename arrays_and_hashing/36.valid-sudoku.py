#
# @lc app=leetcode id=36 lang=python3
#
# [36] Valid Sudoku
#
import collections
# @lc code=start
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        """
        Approach:
        - keep track of a map for the rows, columns, and boxes. Key is location
        index, value is a set of integers
        - iterate every cell and add maps until a duplicate appears
        """
        def get_box_index(row, column):
            row_index = row // 3
            column_index = column // 3
            return row_index, column_index

        rows_map = collections.defaultdict(set)
        columns_map = collections.defaultdict(set)
        boxes_map = collections.defaultdict(set)

        for j in range(len(board)):
            for i in range(len(board[j])):
                
                row, column = j, i
                cell_value = board[row][column]
                if cell_value == ".":
                    continue

                box_index = get_box_index(row, column)
                if cell_value in rows_map[row] or \
                    cell_value in columns_map[column] or \
                    cell_value in boxes_map[box_index]:
                    return False
                
                rows_map[row].add(cell_value)
                columns_map[column].add(cell_value)
                boxes_map[box_index].add(cell_value)

        return True
# @lc code=end

