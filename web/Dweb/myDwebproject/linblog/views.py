from django.shortcuts import render, HttpResponse
import json
from django.http import JsonResponse
from datetime import datetime
from django.db import connection  # 上方這邊導入的標頭，是有被使用到才會亮起來

myCursor=connection.cursor() # 獲取游標對象


# Create your views here.
def index(request):
    return HttpResponse("Hello World!")

def getNews(request):
    list1 = [
        {"title": "那裡的人為什麼這麼帥？", "date": "2023-04-22 23:16:45"},
        {"title": "一夜暴富？！", "date": "2023-06-13 16:55:19"}
    ]
    # str1js = json.dumps(list1)
    # return HttpResponse(str1js)

    return JsonResponse(list1, safe=False)

# 首頁
def myHome(request):
    Playlist = ""
    ArticleList = [
        {"title": "金幣哐啷哐啷全都砸在了派大星頭上？", "date": "2023-04-22 23:16:45"},
        {"title": "敏感詞1一夜暴富？！", "date": "2023-06-13 16:55:19"}
    ]
    return render(request, "index.html", context={"Playlist": Playlist, "ArticleList": ArticleList })

# 關於我
def aboutMe(request):
    return render(request, "aboutme.html")

# 註冊會員
def register(request):
    return render(request, "register.html")

# 註冊會員接口
def regadd(request):
    userID=request.POST['userID']
    username=request.POST['username']
    password=request.POST['password']
    truename=request.POST['truename']
    gender=request.POST['gender']
    age=request.POST['age']
    print(userID, username, password, truename, gender, age)
    myCursor.execute('insert into userinfo(userID, username, password, truename, gender, age) values(%s, %s, %s, %s, %s, %s)',
                     (userID, username, password, truename, gender, age))
    return HttpResponse("會員註冊成功！")

# 印出會員資料
def userlist(request):
    myCursor.execute('select * from userinfo')
    myUsers=myCursor.fetchall() # 可以提取出數據內容
    myheads=[head[0] for head in myCursor.description] # 透過這個語句，可以把每個欄位的名稱挑出來
    myUsers2=[] # 整理過的排版整齊資料
    for user in myUsers:
        uo=zip(myheads, user) # 透過zip方法，可以把兩筆資料對應到一起，就會變成userID : 1000，這樣的鍵值對的形式了
        myUsers2.append(dict(uo)) # 把這個結果塞進 myUser2 裡面，並用dictionary格式呈現
    print(myUsers2)
    return render(request, "userlist.html", {'myUsers' : myUsers, 'myUsers2': myUsers2})

def userEdit(request):
    userID=request.GET['userID']
    print(userID)
    return HttpResponse("有嗎")

