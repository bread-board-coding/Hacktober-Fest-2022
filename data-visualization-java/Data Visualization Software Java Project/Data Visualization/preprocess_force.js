(function() {
  preprocess = {

    links: function(nodes) {
      var map = {},
          node_arr = [],
          country_map = {},
          country_array = [],
          link = [],
          i = 0,
          j = 0;

      function makeMap(name, data){
        var node = map[name];
        if(!node){
          node = map[name] = {name: name, key: i, links: 0, dvalue: 0};
          node_arr[i] = node;
          i++;
        }
        if(node.country == undefined && data.Country != undefined){
          if(country_map[data.Country] == undefined){
            country_map[data.Country] = {name: data.Country, key: j};
            country_array[j] = country_map[data.Country];
            j++;
          }
          node.country = data.Country;
          node.country_code = country_map[data.Country].key;

          if(data.DollarValue.charAt(0) == "$"){
            var re = new RegExp("[$,]", "g");
            node.dvalue = data.DollarValue.replace(re, "");
          }
          node_arr[node.key] = node
        }
      }

      nodes.forEach(function(d) {
        makeMap(d.source, {});
        makeMap(d.target, d)
      });

      nodes.forEach(function(d) {
        if (d.target.length && d.source.length) {
          map[d.target].links++;
          map[d.source].links++;
          link.push({source: map[d.source].key, target: map[d.target].key});
        }
      });

      return {nodes: node_arr, links: link, countries: country_array};
    }

  };
})();
