type quote = {
  quote: string,
  author: string
};

let quote1: quote = {
  quote: "It ain't over till it's over.",
  author: "Yogi Berra"
};

let quote2: quote = {
  quote: "In theory there is no difference between theory and practice. In practice there is.",
  author: "Yogi Berra"
};

let quote3: quote = {
  quote: "You can observe a lot just by watching.",
  author: "Yogi Berra"
};

let quote4: quote = {
  quote: "If you don't know where you are going, you'll end up someplace else.",
  author: "Yogi Berra"
};

let quote5: quote = {
  quote: "If you come to a fork in the road, take it.",
  author: "Yogi Berra"
};

type quotesArray = array(quote);

let quotes: quotesArray = [|quote1, quote2, quote3, quote4, quote5|];

let randomNumberFromRange = (startNumber, endNumber) =>
  Js.Math.random_int(startNumber, endNumber);
