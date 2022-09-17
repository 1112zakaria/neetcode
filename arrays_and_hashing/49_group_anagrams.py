class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        """
        Anagram:
            - two words that contain exact same set of characters
                - words should be equal in length
                - words should contain same set of characters?
        
        Approach #1 (mask mapping):
            - create letter -> key map? (is this needed?)
            - create 26-number mask -> word list map
            - iterate over each word
                - iterate over each letter, creating the word mask
                - add to word list map mapped by mask
            - iterate for each key, append list of words to output
                
        
        """
        # 26-element tuple -> word list map
        mask_map = {}
        
        for word in strs:
            mask = [0 for i in range(26)]
            for letter in word:
                position = int(ord(letter)) - int(ord('a'))
                mask[position] += 1
            mask = tuple(mask)
            if mask not in mask_map:
                mask_map[mask] = []
            mask_map[mask] += [word]
        
        output = []
        for key in mask_map:
            output += [mask_map[key]]
        return output
        