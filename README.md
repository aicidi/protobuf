# Protocol Buffer Example

## 1. Protocol buffer tutorial: C++
https://developers.google.com/protocol-buffers/docs/cpptutorial

## 2. CSV read example: C++ (write), Python (read)
data link: https://www.kaggle.com/jessicali9530/celeba-dataset  
use bounding box csv data

# Dependencies

* protobuf (c++)
```sh
vcpkg install protobuf
```

* protobuf (python)
```sh
pip install protobuf
```

* csv parser (c++) https://github.com/ben-strasser/fast-cpp-csv-parser 
```sh
vcpkg install fast-cpp-csv-parser
```

# Build
```sh
# build c++
mkdir build && cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=/{{your-vcpkg-path}}/vcpkg/scripts/buildsystems/vcpkg.cmake

# generate python pb code (celeba.proto)
protoc -I=./ --python_out=./ celeba.proto
```

# Directory Structure

```
.
├── addressbook_pb2.py
├── addressbook.proto
├── celeba_pb2.py
├── celeba.proto
├── celeba_write.cc
├── CMakeLists.txt
├── list_bbox_celeba.csv
├── read.cc
├── read_csv.py
├── README.md
└── write.cc
```
# Run
1. cd build && ./celeba_write
2. python read_csv.py
