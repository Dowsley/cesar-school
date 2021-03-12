def load_list(f):
    pre_list = f.read().splitlines()

    return [int(e) for e in pre_list]

if __name__ == '__main__':
    with open('out.txt', 'r') as input_file:
        num_list = load_list(input_file)

        has_duplicates = len(num_list) != len(set(num_list))
        print("Há duplicatas") if has_duplicates else  print("Não há duplicatas")
