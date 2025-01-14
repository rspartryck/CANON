#include "stdint.h"
#include "string"
#include "fcntl.h"
#include "unistd.h"
#include "chrono"
#include "cstring"
#include "assert.h"
#include "abstract_log_writer.h"

namespace ssdlogging {

// write log data into memory
class MemLogWriter : public AbstractLogWriter{
	private:
		// a large buffer to store log data
		char *buffer;
		// lock to protect the buffer
		std::mutex buffer_lock;

	public:
		MemLogWriter(int _log_num):
			AbstractLogWriter(_log_num)
		{
			buffer = (char *) malloc(sizeof(char) * MAX_BUFFER_SIZE);
			assert(buffer != nullptr);
		}

		void AppendData(const char *data, size_t size);

		void Sync();

		~MemLogWriter(){
			if(buffer != nullptr)
				free(buffer);
		}
};


void MemLogWriter::AppendData(const char *data, size_t size){
	buffer_lock.lock();
	if (current_buffer_offset + size >= MAX_BUFFER_SIZE){
		// cover the buffer with new data
		current_buffer_offset = 0;
	}
	// assert(current_buffer_offset + size < MAX_BUFFER_SIZE);
	memcpy(buffer + current_buffer_offset, data, size);
	current_buffer_offset += size;
	buffer_lock.unlock();
}

void MemLogWriter::Sync(){
	// TODO
}

}
