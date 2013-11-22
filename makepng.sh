./simple <test.simple>test.dot 
dot -Tpng test.dot -o test.good.png
./simple<../proj4sample/test-expr.smpl>test.dot
    diff ../proj4sample/test-expr.dot test.dot
./simple<../proj4sample/test-if.smpl>test.dot
    diff ../proj4sample/test-if.dot test.dot
./simple<../proj4sample/test-for.smpl>test.dot
    diff ../proj4sample/test-for.dot test.dot

