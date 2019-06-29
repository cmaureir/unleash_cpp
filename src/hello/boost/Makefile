PYTHON_INCLUDE = /usr/include/python3.7m
PYTHON_LIB = /usr/lib

BOOST_INC = /usr/include
BOOST_LIB = /usr/lib

TARGET = simple

${TARGET}.so: ${TARGET}.o
	g++ -shared -Wl,-export-dynamic,-rpath=${PYTHON_LIB} ${TARGET}.o -L${BOOST_LIB} -lboost_python37 -L${PYTHON_LIB} -lpython3.7m -o ${TARGET}.so
${TARGET}.o: ${TARGET}.cpp
	g++ -I${PYTHON_INCLUDE} -I${BOOST_INC} -fPIC -c ${TARGET}.cpp
