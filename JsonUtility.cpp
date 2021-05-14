#include "./Headers/JsonUtility.h"


json::JSON Load( const std::string &str ) {
    size_t offset = 0;
    return std::move( json::parse_next( str, offset ) );
}