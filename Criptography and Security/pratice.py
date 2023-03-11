
alphabet = 'abcdefghijklmnopqrstuvwxyz '

def convert_letters_to_numbers(list_of_letters):
    return [ alphabet.index(x) for x in list_of_letters]

def convert_numbers_to_letters(list_of_numbers):
    return [ alphabet[x] for x in list_of_numbers]

def shift_encrypt(message, key):
    numbers = convert_letters_to_numbers(list(message))
    return convert_numbers_to_letters([ (x + key) % 27 for x in numbers ])

def shift_decrypt(cipher, key):
    numbers = convert_letters_to_numbers(list(cipher))
    return convert_numbers_to_letters([ (x-key if (x - key >= 0) else 26-x-key) for x in numbers ])

letters = [ 'c', ' ', 'a', 'b', 'c', 'd', 'e']
numbers = convert_letters_to_numbers(letters)



encrypted_message = shift_encrypt('deadbeaf', 4)
decrypted_message = shift_decrypt(''.join(encrypted_message), 2)
print(''.join(encrypted_message))
print(''.join(decrypted_message))


