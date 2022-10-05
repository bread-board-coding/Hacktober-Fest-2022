const request = require("request");
const  cheerio = require("cheerio");
const getIssuesHtml = require("./issue");
function getReposPageHtml(url,topic)
{
request(url,cb);

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
        getReposLink(html);
        // console.log(html);
    }
}


function getReposLink(html)
{
    let $ = cheerio.load(html);

    let headingsArr = $(".f3.color-text-secondary.text-normal.lh-condensed");
console.log(topic);
    for(let i=0;i<8;i++)
    {
        let twoanchor = $(headingsArr[i]).find("a");
        let link = $(twoanchor[1]).attr("href");
        //  console.log(link);

         let fullLink = `https://github.com${link}/issues`;
         console.log(fullLink);
console.log(",,,,,")
         getIssuesHtml(fullLink , topic);
    }

    console.log("------------------");
}


}

module.exports = getReposPageHtml;