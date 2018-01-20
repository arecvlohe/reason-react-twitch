open RandomQuotes;
open ParseResponse;

[%bs.raw {|require('./app.css')|}];

let text = ReasonReact.stringToElement;

type state = response;

type action = Click | NewQuote(response);

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  let fetchRandoQuote = (self) => {
    Js.Promise.(
      Fetch.fetch("https://randomquoteapi.glitch.me/funny")
      |> then_(Fetch.Response.text)
      |> then_(text => {
          let result = parseResponse(Js.Json.parseExn(text));
          self.ReasonReact.send(NewQuote(result));
          Js.Promise.resolve();
        })
      ) |> ignore;
  };
  {
  ...component,
  initialState: () => {
    quote: "",
    author: "",
  },
  reducer: (action, _state) => {
    switch action {
    | Click => ReasonReact.SideEffects(fetchRandoQuote);
    | NewQuote(response) => ReasonReact.Update(response);
    }
  },
  didMount: (self) => {
    fetchRandoQuote(self);
    ReasonReact.NoUpdate;
  },
  render: self =>
    <div className="App">
      <div> (text(self.state.quote))</div>
      <div> (text(self.state.author))</div>
      <button onClick=(_event => self.send(Click))>(text("New Random Quote"))</button>
    </div>
  }
};
