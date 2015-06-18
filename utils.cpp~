#include "utils.h"

#include<iostream>
	
uint32_t extract_tag(uint32_t address, const CacheConfig& cache_config) {
  // TODO

   uint32_t num_tag = cache_config.get_num_tag_bits();
   uint32_t num_index = cache_config.get_num_index_bits();
   uint32_t num_offsets = cache_config.get_num_block_offset_bits();
	
   uint32_t tag_shift;

if(num_tag >= 32)
	tag_shift = 0xffffffff;
else
	tag_shift = ((1 << num_tag) -1);

	//std::cout<< "address" << address <<std::endl;
	//std::cout<< "num_tag" << num_tag <<std::endl;
	//std::cout<< "num_index" <<num_index <<std::endl;	
	//std::cout<< "num_offset"<<num_offsets <<std::endl;
	//std::cout<< a <<std::endl;
	//std::cout<< t<<std::endl;	
	//std::cout<< tag<<std::endl;

return (address >> (num_offsets + num_index)) & (tag_shift);
 
}

uint32_t extract_index(uint32_t address, const CacheConfig& cache_config) {
  // TODO

   uint32_t num_index = cache_config.get_num_index_bits();
   uint32_t num_offsets = cache_config.get_num_block_offset_bits();
   uint32_t index_shift;

if(num_index >= 32)
	index_shift = 0xffffffff;
else
	index_shift = ((1 << num_index) -1);


  return (address >> num_offsets) & (index_shift);
  
}

uint32_t extract_block_offset(uint32_t address, const CacheConfig& cache_config) {
  // TODO

  uint32_t num_offsets = cache_config.get_num_block_offset_bits();
  uint32_t offsets_shift;

if(num_offsets >= 32)
	offsets_shift = 0xffffffff;
else
	offsets_shift = ((1 << num_offsets) -1);

	return (address) & (offsets_shift);

}


/*Implement the extract_block_offset, extract_index and extract_tag functions in utils.cpp,
and test them using the unit tests. We’ve provided a regular test Utils.Extract and an edge case
test Utils.Extract32BitTag. Hint: to get a bitstring of N 1s, you can do (1 << N) - 1. However,
shifting by an amount greater than or equal to the width of your type (in this case, 32 bits) is undefined
behavior, so make sure you don’t run into that, hence the edge case test.*/
