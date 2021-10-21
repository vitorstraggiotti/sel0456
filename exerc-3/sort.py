class Item:
    def __init__(self, data: str, key: int):
        self.data = data
        self.key = key

    def __repr__(self):
        return f'{self.key}: {self.data}'

Items = [ Item("john", 3), Item("joe", 2), Item("sara", 1), Item("ana", 4)]
Items.append(Item("billy", 0))

print("Unsorted:")
print(Items)

def compare_Items(a):
    return a.key

Items.sort(key=compare_Items)

print("sorting...")

print(Items)
