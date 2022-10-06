(function() {
  preprocess = {

    // Lazily construct the package hierarchy from class names.
    nodes: function(pairs) {
      var map = {};

      function find(name, data) {
        var node = map[name];
        if (!node) {
          node = map[name] = {name: name, children: []};
          if (name.length){
            node.parent = find("");
            node.parent.children.push(node);
          }
        }
        if (data != undefined && data.target.length) {
          node.children.push({name: data.target, children: [], country: data.Country, dvalue: data.DollarValue, parent: node})
        }
        return node;
      }

      pairs.forEach(function(d) {
        find(d.source, d);
      });

      return map[""].children;
    },

    // Return a list of imports for the given array of nodes.
    links: function(nodes) {
      var map = {},
          link = [];

      // Compute a map from name to node.
      nodes.forEach(function(d) {
        map[d.name] = d;
      });

      // For each import, construct a link from the source to target node.
      nodes.forEach(function(d) {
        console.log("inspecting: ");
        console.log(d);
        if (d.children.length) {
          console.log("found children: "+d.children.length);
          d.children.forEach(function(i) {
            console.log("pushing link:");
            console.log("  map[d.name] = map["+d.name+"]:");
            console.log(map[d.name]);
            console.log("  to:");
            console.log(i);
            link.push({source: map[d.name], target: i});
          });
        }
      });

      return link;
    }

  };
})();
