
def float2bin(f: float) -> str: #type annotation f: float
    """
    precondition is f < 1
    """ # documentation comment in python

    r = ""
    
    for i in range(65):
        f = f * 2
        if f >= 1.0:
            r = r + '1'
            f = f - 1.0
        else:
            r = r + '0'
    return r

print(float2bin(.25))