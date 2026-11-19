# This file will not be committed

import cantools

# should return true with length 64
db = cantools.database.load_file("merged.dbc")
m = db.get_message_by_name("FD_TEST")
print("is_fd:", m.is_fd, "| length:", m.length)

# check to make sure FD_TEST is the only FD message in the database
fd_msgs = [message for message in db.messages if message.is_fd]
print("FD Messages: ", fd_msgs) 

data = m.encode({"fd_test_counter": 1, "fd_test_byte8": 0xDEADBEEF,
                 "fd_test_byte32": 0xCAFEBABE, "fd_test_byte60": 0x01020304})
print("encoded bytes:", len(data))        # should be 64
print("decoded:", m.decode(data))         # should match the values we encoded