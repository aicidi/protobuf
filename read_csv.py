import celeba_pb2 as celeba
import csv
import time
from pprint import pprint

def csv_reader():
    bbox_arr = []

    with open('list_bbox_celeba.csv') as f:
        csv_data = csv.reader(f, delimiter=',')
        next(csv_data)
        
        for data in csv_data:
            bbox = {'image_id': data[0], 'x_1': data[1], 'y_1': data[2],
                    'width': data[3], 'height': data[4]}
            bbox_arr.append(bbox)

def proto_reader():
    csv_data = celeba.Data()
    with open('./build/list_bbox_celeba.bin', 'rb') as f:
        csv_data.ParseFromString(f.read())

def time_check(f):
    s = time.time()
    
    for _ in range(100):
        f()
        
    print(time.time() - s)
    
time_check(csv_reader)
time_check(proto_reader)
