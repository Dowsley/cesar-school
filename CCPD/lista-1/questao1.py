from multiprocessing import Pool, cpu_count
import time

flatten = lambda t: [item for sublist in t for item in sublist]

def load_list(f):
    pre_list = f.read().splitlines()

    return [int(e) for e in pre_list]

def dump_list(f, num_list):
    for i in num_list:
        f.write("%d\n" % i)

def split_list(seq, num):
    avg = len(seq) / float(num)
    out = []
    last = 0.0

    while last < len(seq):
        out.append(seq[int(last):int(last + avg)])
        last += avg

    return out

def remove_duplicates(segment):
    seen = set()
    seen_add = seen.add

    return [e for e in segment if not (e in seen or seen_add(e))]

def task(num_list):
    num_cpus = cpu_count()
    with Pool(num_cpus) as pool:
        segments = split_list(num_list, num_cpus)
        return flatten(pool.map_async(remove_duplicates, segments).get())

if __name__ == '__main__':
    with open('out.txt', 'r') as input_file:
        num_list = load_list(input_file)

        # Test with multithreading
        start = time.time()
        result = remove_duplicates(task(num_list))
        end = time.time()
        print(f"With multithreading: {(end - start) * 1000} milisseconds")

        with open('result.txt', 'w') as output_file:
            dump_list(output_file, result)

        # Test without multithreading
        start = time.time()
        result = remove_duplicates(num_list)
        end = time.time()
        print(f"Without multithreading: {(end - start) * 1000} milisseconds")

