// 18 min
// 43 min

let url = "https://github.com/topics";
const request = require("request");
const  cheerio = require("cheerio");
const { link } = require("fs");
const getReposPageHtml = require("./reposPage");
request(url,cb);
function cb(err,response,html)
{
if(err)
{
    console.log(err);
}
else if(response.statusCode==404)
    {
        console.log("page not found");
    }
else
{
// console.log(html);
topicLink(html);

}
}

function topicLink(html)
{
let $ = cheerio.load(html);
let linkElemArr = $(".no-underline.d-flex.flex-column.flex-justify-center");

for(let i=0;i<linkElemArr.length;i++)
{
    let href = $(linkElemArr[i]).attr("href");
    let topic = href.split("/").pop();
    //  console.log(href);
    let fullLink = `https://github.com/${href}`;
    //  console.log(fullLink);
    getReposPageHtml(fullLink,topic);
}
}
