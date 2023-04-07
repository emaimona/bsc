from secrets import token_bytes



def xor_bytes(lhs, rhs):
    return bytes(l ^ r for l, r in zip(lhs, rhs))

message = 'attack at dawn'.encode()
key = token_bytes(len(message))
cipher = xor_bytes(message, key)
print(xor_bytes(cipher, key).decode())


message = 'you owe me 100$'.encode()
print(message[11:14])

part_to_alter = [0 for _ in range(len(message))] 
part_to_alter[11:14] = message[11:14]
part_to_alter = bytes(part_to_alter)

alter_to = [0 for _ in range(len(message))] 
alter_to[11:14] = b'999'
alter_to = bytes(alter_to)

key = token_bytes(len(message))
cipher = xor_bytes(message, key)
cipher = xor_bytes(cipher, part_to_alter)
