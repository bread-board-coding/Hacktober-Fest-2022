const request = require("request");
const  cheerio = require("cheerio");

function getIssuesHtml(url,topic)
{
request(url,cb)
;

function cb(error,response,html)
{
    if(error)
    {
        console.log(error);
    }
    else if(response.statusCode==404)
    {
        console.log("page not found");
    }
    else
    {
        //  console.log(html);
        getIssues(html);
       
    }
}


function getIssues(html)
{
    let $ = cheerio.load(html);
    let issuesElemArr = $(".Link--primary.v-align-middle.no-underline.h4.js-navigation-open.markdown-title");
    // console.log(issuesElemArr.length);
    let arr = [];
    for (let i = 0; i < issuesElemArr.length; i++) {
        let link = $(issuesElemArr[i]).attr("href");
        // console.log(link);
        arr.push(link);
    }
    console.log(topic,arr)

}

}

module.exports = getIssuesHtml;