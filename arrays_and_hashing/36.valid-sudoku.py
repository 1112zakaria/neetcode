#
# @lc app=leetcode id=36 lang=python3
#
# [36] Valid Sudoku
#

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

        rows_map = {k:set() for k in range(9)}
        columns_map = {k:set() for k in range(9)}
        boxes_map = {}
        for j in range(9):
            for i in range(9):
                boxes_map[i,j] = set()

        for j in range(len(board)):
            for i in range(len(board[j])):
                row, column = j, i
                cell_value = board[row][column]
                if cell_value == ".":
                    continue

                # check rows map
                if cell_value in rows_map[row]:
                    return False
                else:
                    rows_map[row].add(cell_value)

                # check columns map
                if cell_value in columns_map[column]:
                    return False
                else:
                    columns_map[column].add(cell_value)

                # check boxes map
                box_index = get_box_index(row, column)
                if cell_value in boxes_map[box_index]:
                    return False
                else:
                    boxes_map[box_index].add(cell_value)

        return True
# @lc code=end

