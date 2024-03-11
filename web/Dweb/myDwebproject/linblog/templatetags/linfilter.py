from django import template
register=template.Library()

@register.filter
def myFilterMGW(value, arg1):
    mystr1 = str(value)
    if mystr1.find("敏感詞1")>=0:
        return mystr1.replace("敏感詞1", arg1)
    else:
        return value