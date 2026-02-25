import os

class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None  

class HashTable:
    def __init__(self, initial_capacity=10):
        self.capacity = initial_capacity
        self.size = 0
        self.table = [None] * self.capacity

    def _hash_function(self, key: str) -> int:
        B = 31
        hash_value = 0
        for ch in key:
            hash_value = (hash_value * B + ord(ch)) % self.capacity
        return hash_value

    def get(self, key: str):
        index = self._hash_function(key)
        node = self.table[index]

        while node is not None:
            if node.key == key:
                return node.value
            node = node.next

        return None
    
    def put(self, key: str, value):
        index = self._hash_function(key)
        node = self.table[index]

        while node is not None:
            if node.key == key:
                node.value = value
                return
            node = node.next

        new_node = Node(key, value)
        new_node.next = self.table[index]
        self.table[index] = new_node
        self.size += 1

        load_factor = self.size / self.capacity
        if load_factor >= 1.5:
            self._resize()

    def _resize(self):
        old_table = self.table
        self.capacity *= 2
        self.table = [None] * self.capacity
        self.size = 0
        
        for head in old_table:
            node = head
            while node is not None:
                next_node = node.next
                
                new_index = self._hash_function(node.key)
                
                node.next = self.table[new_index]
                self.table[new_index] = node
                self.size += 1
                
                node = next_node

def count_word_frequency(text: str) -> HashTable:
    ht = HashTable()

    words = text.split()

    for word in words:
        word = word.lower()

        current_count = ht.get(word)
        if current_count is None:
            ht.put(word, 1)
        else:
            ht.put(word, current_count + 1)

    return ht

if __name__ == "__main__":
    print("Running Solution Tests...")

    print("\n--- Real Dataset Test ---")
    current_dir = os.path.dirname(os.path.abspath(__file__))
    target_file = os.path.join(current_dir, "sample_text.txt")
    try:
        if not os.path.exists(target_file):
            print(f"[ERROR] '{target_file}' not found.")
            print(f"Current Working Directory is: {os.getcwd()}") 
        else:
            with open(target_file, "r", encoding="utf-8") as f:
                text_data = f.read()
            word_counts = count_word_frequency(text_data)
            print(f"Total Unique Words: {word_counts.size}")
            print(f"Final Table Capacity: {word_counts.capacity}")
    except FileNotFoundError:
        print(f"Error: The file was not found.")