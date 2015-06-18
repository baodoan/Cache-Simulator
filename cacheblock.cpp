#include "cacheblock.h"

uint32_t Cache::Block::get_address() const {
  // TODO

/*
Implement the get_address function in cacheblock.cpp, which computes the starting memory address
of a block. Test it using the unit tests; we’ve provided one test called CacheBlock.GetAddress.
At this point, all of our provided unit tests should pass.

*/

  return ( (this->_tag)<< (_cache_config.get_num_block_offset_bits() + _cache_config.get_num_index_bits()) | (this->_index << _cache_config.get_num_block_offset_bits()) ); 

}
