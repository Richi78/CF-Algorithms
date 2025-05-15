# try:
#     while True:
#         s=input()
#         d=dict(list)
#         d['[']=[];d[']']=[]
#         # while True:
#         for i in range(len(s)):
#             if s[i]=="[":
#                 d[s[i]]
#             elif s[i]=="]":
#                 d[s[i]]+=1
#         for x in d
        
            

        

# except EOFError:
#     pass  

import sys

for line in sys.stdin:
    text = []   # Lista principal donde se almacenará el texto final
    temp = []   # Lista temporal para almacenar el texto cuando estamos en "Home"
    home_mode = False  # Indica si estamos en "Home"

    for char in line.strip():
        if char == '[':  
            text = temp + text  # Insertamos el texto almacenado en Home al inicio
            temp = []           # Limpiamos la lista temporal
            home_mode = True
        elif char == ']':  
            text = temp + text  # Insertamos el texto almacenado en Home al inicio
            temp = []           # Limpiamos la lista temporal
            home_mode = False
        else:
            if home_mode:
                temp.append(char)  # Guardamos temporalmente en "Home"
            else:
                text.append(char)  # Insertamos normalmente al final

    text = temp + text  # Insertamos cualquier texto pendiente en Home
    print("".join(text))  # Imprimimos el resultado