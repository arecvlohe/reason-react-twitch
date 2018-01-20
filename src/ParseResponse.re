type response = {
  quote: string,
  author: string
};

let parseResponse = (json: Js.Json.t) : response =>
  Json.Decode.{
    quote: field("quote", string, json),
    author: field("author", string, json)
  };
