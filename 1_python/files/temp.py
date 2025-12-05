a = 5.0
b = 9.0
c = 32.0

def convert_to_celcius(F:float):
    return (F-c)*a/b

def convert_to_farenheit(C:float):
    return C*b/a + c