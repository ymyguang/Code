if (typeof WechatTSG == "undefined") WechatTSG = {};
if (typeof WechatTSG.Web == "undefined") WechatTSG.Web = {};
if (typeof WechatTSG.Web.Seat == "undefined") WechatTSG.Web.Seat = {};
if (typeof WechatTSG.Web.Seat.RoomSeatdetail == "undefined") WechatTSG.Web.Seat.RoomSeatdetail = {};
WechatTSG.Web.Seat.RoomSeatdetail_class = function () { };
Object.extend(WechatTSG.Web.Seat.RoomSeatdetail_class.prototype, Object.extend(new AjaxPro.AjaxClass(), {
    ShowAllSeats: function (StrRoomNoParm) {
        return this.invoke("ShowAllSeats", { "StrRoomNoParm": StrRoomNoParm }, this.ShowAllSeats.getArguments().slice(1));
    },
    url: '/ajaxpro/WechatTSG.Web.Seat.RoomSeatdetail,WechatTSG.Web.ashx'
}));
WechatTSG.Web.Seat.RoomSeatdetail = new WechatTSG.Web.Seat.RoomSeatdetail_class();
