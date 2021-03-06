#include "simplecache.h"

int SimpleCache::find(int index, int tag, int block_offset) {
  // read handout for implementation details


/*
For find, you will have to look up the set of blocks that corresponds to the given index, and find the
correct block within that: meaning that the block should be valid, and its tag should match the given tag.
If such a block exists, return the correct byte within the block. If not, return 0xdeadbeef, the universal
slaughterhouse ‘bad address’ code.
*/

	auto find_set = _cache.find(index);
	if(find_set != _cache.end())
	{
	 for(auto block : find_set->second)
		{
			if(block.valid() && block.tag() == tag)
			return block.get_byte(block_offset);	
		}		
		
	}
	
  return 0xdeadbeef;
}

void SimpleCache::insert(int index, int tag, char data[]) {
  // read handout for implementation details

/*
For insert, you will again look up the set of blocks corresponding to the given index. If there’s an invalid
block in the set, that means there is no need for replacement: just replace the invalid block with the
right information. If not, replace the 0th block of the set.
*/

	auto find_set = _cache.find(index);
	if(find_set != _cache.end())
  	 {
		for(auto &block : find_set->second)
		{
			if(!block.valid() )
			{
				block.replace(tag, data);
				return;
			}
		}
		// If there're no invalid block
		  find_set->second[0].replace(tag ,data);
		
	 }
   return;
}
