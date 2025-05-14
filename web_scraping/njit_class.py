import requests
from bs4 import BeautifulSoup
from pymongo import MongoClient

html = '''
<table class="course-table">
  <thead>
    <tr>
      <th>Course Code</th>
      <th>Title</th>
      <th>Instructor</th>
    </tr>
  </thead>
  <tbody>
    <tr class="data-row">
      <td>
        <div class="code-box">
          <span class="course-code">CS101</span>
        </div>
      </td>
      <td>
        <div class="title-box">
          <span class="course-title">Intro to CS</span>
        </div>
      </td>
      <td>
        <div class="instructor-box">
          <span class="instructor">Dr. Smith</span>
        </div>
      </td>
    </tr>
    <tr class="data-row">
      <td>
        <div class="code-box">
          <span class="course-code">MATH211</span>
        </div>
      </td>
      <td>
        <div class="title-box">
          <span class="course-title">Calculus III</span>
        </div>
      </td>
      <td>
        <div class="instructor-box">
          <span class="instructor">Prof. Johnson</span>
        </div>
      </td>
    </tr>
  </tbody>
</table>
'''

soup = BeautifulSoup(html, "html.parser")

# Encuentra solo las filas con clase "data-row"
rows = soup.find_all("tr",{"class" :"data-row"})
courses = []

for i in rows:
    code = i.find("span", {"class" : "course-code"}).string
    title = i.find("span", {"class" : "course-title"}).string
    instructor = i.find("span", {"class" : "instructor"}).string

    data = ({"code":code,"title": title, "instructor":instructor})
    courses.append(data)
# Mostrar resultado final
print(courses)